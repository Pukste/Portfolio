// Listat_maarittely.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <iostream>

class Solmu {
public:
	int _data;
	Solmu *_next;
	
};
Solmu* head = nullptr;

void printList() {
	Solmu *ptr = head;
	
	while (ptr != nullptr) {
		printf("\n%d", ptr->_data);
		ptr = ptr->_next;
	}
}

bool findSolmu(const Solmu* start, int value) {
	
	const Solmu *curr = start;
	while (curr->_data != value) {

	
		if (curr->_next == nullptr) {
			printf("\nei ole");
			return false;
		}
		else {
			curr = curr->_next;
		}
	}
	printf("\njuu\n");
	return true;
}

void insertSolmu(Solmu* prev, int uusiValue) {

	Solmu* s = (Solmu*)malloc(sizeof(Solmu));
	s->_data = uusiValue;
	s->_next = prev->_next;
	prev->_next = s;
	printList();
	free(s);
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
	head = s1;

	s2->_data = 20;
	s2->_next = s3;
	
	s3->_data = 30;
	s3->_next = s4;
	
	s4->_data = 40;
	s4->_next = s5;
	
	s5->_data = 50;
	s5->_next = s6;
	
	s6->_data = 60;
	s6->_next = s7;
	
	s7->_data = 70;
	s7->_next = s8;
	
	s8->_data = 80;
	s8->_next = s9;
	
	s9->_data = 90;
	s9->_next = s10;
	
	s10->_data = 100;
	s10->_next = nullptr;


	printf("Solmut ennen inserttiä:\n");
	printList();

	findSolmu(head, 40);
	printf("Solmut insertin jälkeen:\n");
	insertSolmu(s5, 134);





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

