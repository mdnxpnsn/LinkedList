/*
 * List.hpp
 *
 *  Created on: Apr 11, 2019
 *      Author: d-w-h
 */

#ifndef LIST_HPP_
#define LIST_HPP_

#include "User.hpp"

class List {
private:
    nd* head;
    nd* curr;
    nd* temp;
    int size;
public:
	List();
	void insert_node(nd node);
	void delete_node(nd* node_ptr);
	void print_list();
	nd* search_list(int key);
	int get_size();
};

#endif /* LIST_HPP_ */
