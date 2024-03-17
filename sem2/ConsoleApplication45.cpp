﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream> 

int main() {
    setlocale(LC_ALL, "ru");

    std::cout << "Enter the string first, then the character: " << std::endl;

    std::string stroka_line;
    char bukva_char;

    std::getline(std::cin, stroka_line);
    std::cin >> bukva_char;

    std::stringstream ss(stroka_line);
    std::vector<std::string> words;
    std::string word;
    while (ss >> word) {
        words.push_back(word);
    }

    auto count_and_show_words = [bukva_char](const std::vector<std::string>& words) {
        std::vector<std::string> filtered_words;
        for (const auto& word : words) {
            if (!word.empty() && word[0] == bukva_char) {
                filtered_words.push_back(word);
            }
        }
        return filtered_words;
        };

    std::vector<std::string> filtered_words = count_and_show_words(words);
    std::cout << "Number of words starting with letter '" << bukva_char << "': " << filtered_words.size() << std::endl;
    std::cout << "These are the words: ";
    for (const auto& fw : filtered_words) {
        std::cout << fw << " ";
    }
    std::cout << std::endl;

    return 0;
}