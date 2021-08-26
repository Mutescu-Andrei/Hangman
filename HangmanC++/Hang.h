#pragma once
#include <fstream>
#include<ctime>
#include <stdlib.h> 
#include <string.h>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;


class Player {
protected:
	char* jucator;
	double highscore;
public:
	Player(const char* jucator = " ", double highscore = 0) {
		this->jucator = new char[strlen(jucator) + 1];
		strcpy(this->jucator, jucator);
		this->highscore = 0;

	}

	virtual ~Player()
	{
		if (jucator) {
			delete[]jucator;
			jucator = 0;
		}

	}
	virtual void scor() = 0;
	virtual double getscor() = 0;
};

class Hangman :virtual public Player {
private:
	int  greseli;

	char* cuvant;
public:
	char* reper;
public:
	Hangman(const char* jucator, double highscore, const char* cuvant, int greseli, char* reper) :Player(jucator, highscore)
	{
		this->cuvant = new char[strlen(cuvant) + 1];
		strcpy(this->cuvant, cuvant);
		this->greseli = 0;
		this->reper = new char[strlen(reper) + 1];
		strcpy(this->reper, reper);
	}
	Hangman();

	void scor() { highscore = 0; }
	Hangman& operator= (const Hangman& s);
	void arata() { cout << this->cuvant; }
	void afiseazacuv() {
		cout << endl;
		cout << "cuvantul: " << this->reper << endl;

	}
	double getscor() { return this->highscore; };
	void afiseazagreseli()
	{	//cout << "greseli: " << this->greseli << endl;}
	}
	void setcuvant(char* pp) {
		cuvant = new char[strlen(pp) + 1];
		strcpy(cuvant, pp);
	}
	void setreper(char* pp2) {
		reper = new char[strlen(pp2) + 1];
		memset(reper, 0, 100);
		strncpy(reper, pp2, strlen(pp2));
	}


	void greseala(Hangman&);
	void setgreseala(int g) { this->greseli = 7 - g; }
	void scadincercari() { this->greseli = this->greseli + 1; }
	void check();
	void lafel();
	void input(Hangman&);

	void consola();
	friend ostream& operator<<(ostream&, const Hangman&);
	friend istream& operator>>(istream&, Hangman&);
};