#include "ladder.h"
#include <iostream>
#include <string>

void test_edit_distance() {
    std::string longer = "chat";
    std::string shorter = "cat";
    std::string diff1 = "cbt";
    std::string diff2 = "cby";
    std::string too_long = "banana";
    std::string app = "app";
    std::string appl = "appl";

    bool one_diff_len = edit_distance_within(longer, shorter, 1);
    bool one_char_diff = edit_distance_within(shorter, diff1, 1);
    bool two_char_diff = edit_distance_within(shorter, diff2, 1);
    bool way_longer = edit_distance_within(shorter, too_long, 1);
    bool one_off = edit_distance_within(app, appl, 1);
    if (one_diff_len) {
        std::cout << "One different char in len in true " << '\n';
    }
    if (one_char_diff) {
        std::cout << "One different char in content in true " << '\n';
    }
    if (!two_char_diff) {
        std::cout << "Two different char in content in false " << '\n';
    }
    if (!way_longer) {
        std::cout << "Way longer word is false " << '\n';
    }
    if (one_off) {
        std::cout << "True.." << '\n';
    }
}

void test_load_words() {
    std::set<string> word_list;    
    load_words(word_list, "src/words.txt");
    for (const auto& word : word_list) {
        std::cout << word << '\n';
    }
}

void test_generate_words() {
    std::set<string> word_list;    
    load_words(word_list, "src/words.txt");
    std::vector<std::string> test = generate_word_ladder("cat", "dog", word_list);
    print_word_ladder(test);
}

void test_generate_neigh() {
    vector<std::string> test = generate_neighbors("cat");
    print_word_ladder(test);
}
int main() {
    // test_edit_distance();
    // test_load_words();
    test_generate_words();
    verify_word_ladder();
    // test_generate_neigh();
    return 0;
}