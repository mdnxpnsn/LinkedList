/*
 * main.cpp
 *
 *  Created on: Apr 11, 2019
 *      Author: d-w-h
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "../inc/List.hpp"
#include "../inc/User.hpp"

int main(int argc, char* argv[])
{
	List list;
	nd node_1 = {0, 2.718, NULL, NULL};
	nd node_2 = {1, 3.141, NULL, NULL};
	nd node_3 = {2, 2.22, NULL, NULL};
	nd* node_target_1 = NULL;
	nd* node_target_2 = NULL;
	nd* node_target_3 = NULL;

	list.print_list();
	list.insert_node(node_1);
	list.insert_node(node_2);
	list.insert_node(node_3);
	list.print_list();
	node_target_1 = list.search_list(0);
	node_target_2 = list.search_list(1);
	node_target_3 = list.search_list(2);

	std::cout << "deleting nodes" << std::endl;
	list.delete_node(node_target_2);
	list.delete_node(node_target_3);
	list.delete_node(node_target_1);
	list.print_list();

	int size = list.get_size();
	std::cout << "size " << size << std::endl;
	return 0;
}
