#include "ladder.h"
#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <cmath>
#include <fstream>

void error(string word1, string word2, string msg) {
    std::cout << word1 << word2 << msg << '\n';
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int str1_len = str1.length();
    int str2_len = str2.length();
    if (abs(str1_len - str2_len) > d) {
        return false;
    }

    int str1_counter = 0;
    int str2_counter = 0;
    int diff = 0;
    while (str1_counter < str1_len && str2_counter < str2_len) {
        if (str1[str1_counter] == str2[str2_counter]) {
            ++str1_counter;
            ++str2_counter;
        } else {
            if (str1_len < str2_len) {
                ++str2_counter;
            } else if (str1_len > str2_len) {
                ++str1_counter;
            } else {
                ++str1_counter;
                ++str2_counter;
                ++diff;
            }
        }

        if (diff > d) {
            return false;
        }
    }

    if (str1_counter == str2_counter || abs(str1_counter - str2_counter) == d) {
        return true;
    }

    return false;
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    if (begin_word == end_word) {
        vector<std::string> empty;
        return empty;
    }
    std::queue<vector<std::string> > ladder_queue;
    std::vector<std::string> begin_ladder;
    begin_ladder.push_back(begin_word);
    ladder_queue.push(begin_ladder);
    std::set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<std::string> ladder = ladder_queue.front();
        ladder_queue.pop();
        std::string last_word = ladder.back();
        for (const auto& word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (visited.find(word) != visited.end()) {
                    visited.insert(word);
                    vector<std::string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word) {
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    vector<std::string> empty;
    return empty;
}

void load_words(std::set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    if (!in) {
        throw runtime_error("Can't open input file");
    }
    std::string word;
    while (in) {
       in >> word; 
       word_list.insert(word);
    }
    in.close();
}

void print_word_ladder(const vector<string>& ladder) {
    if (!ladder.empty()) {
        std::cout << "Word ladder found: ";
        for (const auto& word : ladder) {
            std::cout << word << " ";
        }        
    } else {
        std::cout << "No word ladder found.";
    }
    std::cout << '\n';
}

void verify_word_ladder() {
    return;
}