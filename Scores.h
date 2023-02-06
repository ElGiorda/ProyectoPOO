#ifndef SCORES_H
#define SCORES_H
#include <vector>
using namespace std;

struct Score{
	char alias[3]={'-','-','-'};
	int puntos = 0;
	int enemy_killed = 0;
};

class Scores {
public:
	Scores();
	
	void LoadHighscore();
	void SaveHighscore();
	
	void Insert_Score(Score);
	
	bool Mayor (const Score&,const Score&);
	
	vector <Score> return_scores();
private:
	vector <Score> s_highscore;
};

#endif

