#include "Scores.h"
#include <fstream>
using namespace std;

Scores::Scores() : s_highscore(10) {
	LoadHighscore();
}

void Scores :: LoadHighscore(){
	ifstream ifile("highscore.dat", ios::binary); //lectura
	if(!ifile.is_open()){ //Si no existe, se crea
		ofstream ofile("highscore.dat", ios::binary);
		ofile.close();
		return; // al crearse vuelve al principio
	}
	
	Score aux;
	for(int i=0;i<10;i++) { 
		ifile.read(reinterpret_cast<char*>(&aux),sizeof(Score));
		s_highscore[i] = aux; //leo y guardo
	}
	ifile.close();
}

void Scores :: SaveHighscore(){
	
	ofstream ofile("highscore.dat", ios::binary|ios::trunc);
	
	for(size_t i = 0; i < s_highscore.size(); ++i){
		ofile.write(reinterpret_cast<char*>(&(s_highscore[i])), sizeof(s_highscore[i]));
	}
	ofile.close();
}

bool Scores::Mayor (const Score &A,const Score &B) {
	if (A.puntos>B.puntos) {
		return true;
	} else {
		return false;
	}
}

void Scores::Insert_Score(Score B) {
	vector<Score> High;
	vector<Score>::iterator it = s_highscore.begin();
	while(Mayor(*it, B) && it != s_highscore.end()){
		High.push_back(*it);
		++it;
	}
	
	High.push_back(B);
	while(it != s_highscore.end()){
		High.push_back(*it);
		++it;
	}
	
	s_highscore = High;
	
	s_highscore.resize(10);
}
vector <Score> Scores::return_scores(){
	return s_highscore;
}
