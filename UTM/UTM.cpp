#include "UTM.hpp"

UTM::row_node::row_node() {
    next_row = nullptr;
}

UTM::row_node::col_node::col_node() {
    next_col = nullptr;
    val = 1;
}

UTM::UTM(int length) {
    this->length = length;
    init();
}

void UTM::add(UTM *other) {
    for (row_node *tmp_row = row_head, *tmp_row_other = other->row_head;
         tmp_row != nullptr && tmp_row_other != nullptr;
         tmp_row = tmp_row->next_row, tmp_row_other = tmp_row_other->next_row) {
        
        for (row_node::col_node *tmp_col = tmp_row->col_head, *tmp_col_other = tmp_row_other->col_head;
             tmp_col != nullptr && tmp_col_other != nullptr;
             tmp_col = tmp_col->next_col, tmp_col_other = tmp_col_other->next_col) {
            
            tmp_col->val += tmp_col_other->val;
        }
    }
}

UTM::row_node::col_node *UTM::at(int row, int col) {
    if (row < 0 || row >= length || col < row || col >= length) throw std::exception();
    
    col -= row;
    
    row_node *tmp_row = nullptr;
    for (int i = 0; i <= row; i++) {
        if (i == 0) tmp_row = row_head;
        else tmp_row = tmp_row->next_row;
    }
    
    row_node::col_node *tmp_col = nullptr;
    for (int i = 0; i <= col; i++) {
        if (i == 0) tmp_col = tmp_row->col_head;
        else tmp_col = tmp_col->next_col;
    }
    
    return tmp_col;
}

void UTM::init() {
    row_node *tmp_row = nullptr;
    for (int i = 0; i < length; i++) {
        if (i == 0) row_head = tmp_row = new row_node;
        else tmp_row = tmp_row->next_row = new row_node;
        
        row_node::col_node *tmp_col = nullptr;
        for (int i = 0; i < length; i++) {
            if (i == 0) tmp_row->col_head = tmp_col = new row_node::col_node;
            else tmp_col = tmp_col->next_col = new row_node::col_node;
        }
    }
}

std::string UTM::to_string() {
    std::stringstream out;
    row_node *row_tmp = nullptr;
    for (int i = 0; i < length; i++) {
        if (i == 0) row_tmp = row_head;
        else row_tmp = row_tmp->next_row;
        for (int j = 0; j < i; j++) {
            out << std::setw(5) << "0";
        }
        row_node::col_node *col_tmp = nullptr;
        for (int j = i; j < length; j++) {
            if (j == i) col_tmp = row_tmp->col_head;
            else col_tmp = col_tmp->next_col;
            out << std::setw(5) << col_tmp->val;
        }
        out << std::endl;
    }
    return out.str();
}

UTM::~UTM() {
    row_node *row = row_head;
    while (row != nullptr) {
        row_node::col_node *col = row->col_head;
        while (col != nullptr) {
            row_node::col_node *tmp_col = col->next_col;
            delete col;
            col = tmp_col;
        }
        row_node *tmp_row = row->next_row;
        delete row;
        row = tmp_row;
    }
}
