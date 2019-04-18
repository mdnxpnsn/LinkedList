/*
 * List.cpp
 *
 *  Created on: Apr 11, 2019
 *      Author: d-w-h
 */

#include <iostream>
#include "../inc/List.hpp"
#include "../inc/User.hpp"

List::List() {
	this->head = NULL;
	this->curr = NULL;
	this->temp = NULL;
	this->size = 0;
}

void List::insert_node(nd node) {
	if(this->head == NULL) {
		nd* new_node = new nd;
		new_node->prev = NULL;
		new_node->next = NULL;
		new_node->key = node.key;
		new_node->data = node.data;
		this->head = new_node;
		this->curr = new_node;
		this->temp = new_node;
		this->size++;
	}
	else {
		nd* new_node = new nd;
		new_node->prev = NULL;
		new_node->next = this->curr;
		new_node->key = node.key;
		new_node->data = node.data;
		this->curr->prev = new_node;
		this->head = new_node;
		this->curr = new_node;
		this->size++;
	}
}

void List::delete_node(nd* node) {
	if(this->head == NULL) {
		std::cout << "attempting to delete element from empty list" << std::endl;
	}
	else if(node->prev != NULL && node->next != NULL && node != NULL) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete node;
		this->size--;
	}
	else if (node->prev != NULL && node->next == NULL && node != NULL) {
		node->prev->next = NULL;
		this->temp = this->head;
		delete node;
		this->size--;
	}
	else if(node->prev == NULL && node->next != NULL && node != NULL) {
		node->next->prev = NULL;
		this->head = node->next;
		this->curr = node->next;
		delete node;
		this->size--;
	}
	else if(node->prev == NULL && node->next == NULL && node != NULL) {
		this->head = NULL;
		this->curr = NULL;
		this->temp = NULL;
		delete node;
		this->size--;
	}
	else {};
}

void List::print_list() {
	this->temp = this->head;
	if(this->head != NULL) {
		while(this->temp != NULL) {
			std::cout << this->temp->data << std::endl;
			this->temp = this->temp->next;
		}
	}
	else {
		std::cout << "attempting to print empty list" << std::endl;
	}
}

nd* List::search_list(int key) {
	nd* node_ptr = NULL;
	if(this->head != NULL) {
		this->temp = this->head;
		while(this->temp != NULL) {
			if(this->temp->key == key) {
				node_ptr = this->temp;
			}
			this->temp = this->temp->next;
		}
	}
	else {
		std::cout << "attempting to search through empty list" << std::endl;
	}

	return node_ptr;
}

int List::get_size() {
	return this->size;
}
