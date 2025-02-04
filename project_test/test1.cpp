#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;

// Callback function to handle API response
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

class Chatbot {
private:
    std::string api_key;
    CURL* curl;
    struct curl_slist* headers = NULL;

public:
    Chatbot(const std::string& key) : api_key(key) {
        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();
        
        // Set up headers
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "anthropic-version: 2023-06-01");
        std::string auth_header = "x-api-key: " + api_key;
        headers = curl_slist_append(headers, auth_header.c_str());
    }

    ~Chatbot() {
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }
std::string getResponse(const std::string& user_input) {
    if (!curl) return "Error initializing CURL";

    std::string response_string;

    // Prepare the JSON payload for Claude API
    json payload = {
        {"model", "claude-3-sonnet-20240229"},
        {"max_tokens", 1024},
        {"messages", {{
            {"role", "user"},
            {"content", user_input}
        }}}
    };

    std::string payload_str = payload.dump();

    curl_easy_setopt(curl, CURLOPT_URL, "https://api.anthropic.com/v1/messages");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload_str.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        return "Error: " + std::string(curl_easy_strerror(res));
    }

    try {
        json response_json = json::parse(response_string);

        // Debug: Print the response to verify its structure
        //std::cout << "Raw API Response: " << response_json.dump(4) << std::endl;

        // Validate and extract the response
        if (response_json.contains("content") && !response_json["content"].is_null()) {
            return response_json["content"][0]["text"].get<std::string>();
        } else if (response_json.contains("error")) {
            return "API Error: " + response_json["error"].get<std::string>();
        } else {
            return "Unexpected API response format.";
        }
    } catch (json::parse_error& e) {
        return "Error parsing response: " + std::string(e.what());
    } catch (json::type_error& e) {
        return "Type error in response: " + std::string(e.what());
    }
}

    
};

int main() {
    /**
     api_key;
    std::cout << "Enter your Anthropic API key: ";
    std::getline(std::cin, api_key);*/
    std::string api_key;
    api_key = "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";

    Chatbot bot(api_key);
    std::string user_input;

    std::cout << "Claude Chatbot initialized. Type 'quit' to exit.\n";

    while (true) {
        std::cout << "\nYou: ";
        std::getline(std::cin, user_input);

        if (user_input == "quit") break;

        std::string response = bot.getResponse(user_input);
        std::cout << "Chatty: " << response << std::endl;
    }

    return 0;
}