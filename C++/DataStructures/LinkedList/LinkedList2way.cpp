// KahdenSuunnanLista.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <iostream>

class Solmu {
public:
	int _data;
	Solmu *_next;
	Solmu *_prev;
};
Solmu* head = nullptr;
Solmu* end = nullptr;

void printList() {
	Solmu *ptr = head;
	printf("Taman hetkiset solmut :");
	while (ptr != nullptr) {
		printf("\n%d", ptr->_data);
		ptr = ptr->_next;
	}
}

void printList(const Solmu* last){
	const Solmu *curr = last;
	printf("\nLista toisinpain :");
	while (curr != nullptr) {
		printf("\n%d", curr->_data);
		curr = curr->_prev;
	}


}

int main()
{
	Solmu* s1 = (Solmu*)malloc(sizeof(Solmu));
	Solmu* s2 = (Solmu*)malloc(sizeof(Solmu));
	Solmu* s3 = (Solmu*)malloc(sizeof(Solmu));
	Solmu* s4 = (Solmu*)malloc(sizeof(Solmu));
	Solmu* s5 = (Solmu*)malloc(sizeof(Solmu));
	Solmu* s6 = (Solmu*)malloc(sizeof(Solmu));
	Solmu* s7 = (Solmu*)malloc(sizeof(Solmu));
	Solmu* s8 = (Solmu*)malloc(sizeof(Solmu));
	Solmu* s9 = (Solmu*)malloc(sizeof(Solmu));
	Solmu* s10 = (Solmu*)malloc(sizeof(Solmu));

	s1->_data = 10;
	s1->_next = s2;
	s1->_prev = nullptr;
	head = s1;

	s2->_data = 20;
	s2->_next = s3;
	s2->_prev = s1;

	s3->_data = 30;
	s3->_next = s4;
	s3->_prev = s2;

	s4->_data = 40;
	s4->_next = s5;
	s4->_prev = s3;

	s5->_data = 50;
	s5->_next = s6;
	s5->_prev = s4;

	s6->_data = 60;
	s6->_next = s7;
	s6->_prev = s5;

	s7->_data = 70;
	s7->_next = s8;
	s7->_prev = s6;

	s8->_data = 80;
	s8->_next = s9;
	s8->_prev = s7;

	s9->_data = 90;
	s9->_next = s10;
	s9->_prev = s8;

	s10->_data = 100;
	s10->_next = nullptr;
	s10->_prev = s9;
	end = s10;


	printList();

	printList(end);

	free(s1);
	free(s2);
	free(s3);
	free(s4);
	free(s5);
	free(s6);
	free(s7);
	free(s8);
	free(s9);
	free(s10);


}

