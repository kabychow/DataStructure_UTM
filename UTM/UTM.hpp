#ifndef UTM_hpp
#define UTM_hpp

#include <iostream>
#include <sstream>
#include <iomanip>

struct UTM {
    int length;
    struct row_node {
        row_node *next_row;
        struct col_node {
            int val;
            col_node *next_col;
            col_node();
        } *col_head;
        row_node();
    } *row_head;

    UTM(int length);
    void add(UTM *other);
    row_node::col_node *at(int row, int col);
    void init();
    std::string to_string();
    ~UTM();
};

#endif
