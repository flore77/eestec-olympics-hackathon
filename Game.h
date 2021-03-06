#ifndef __GAME_H__
#define __GAME_H__

#include <utility>
#include <queue>
#include <algorithm>

#define WALL_POSITION 15
#define MaxS (37*37)

#define MX {1, -1, 0, 0}
#define MY {0, 0, 1, -1}
#define NR_MOVES 4

#define DOWN 4
#define UP 2
#define RIGHT 1
#define LEFT 3
#define STAY 0

#define MaxDanger 1000
#define RADIUS 3

#define MAX_DISTANCE 100000

#define BARRIER 5

class Game {
public:
	Game();
	Game(int N, int M);
	virtual ~Game();

	void readId(int *);
	void readHeader(int *);
	void readMatrix(int *);

	void prettyPrint();

	int getN();

	int getM();

	void makeMove(int * buffer);
	void findPositions();
	void findOpId();
//private:

	bool isWall(int x, int y);

	int getFlameDuration(int x, int y);

	int getExplosionTime(int x, int y);

  std::pair<int, std::pair<int, int> > BFS();
  bool isValidMove(int x, int y);

  //Danger.
  void calculateDanger();
  int getDanger(int, int);
  void calculateEstimatedExplosionTime();
  int getEstimatedExplosionTime(int, int);

  // AI.
  double survival(int, int);
  double area(int, int);
  double getScore(int, int, bool);
  std::pair<int, bool> getBestMove();

	std::pair<int, int> _myPosition;
	std::pair<int, int> _opPosition;
	int _moveCounter;
	int _opId;
	int _myId;
	int _currentMove;
	int _aggresiveModeStart;
	int _maxMove;
	int _N, _M;
	int _board[MaxS];
  int _distOp;
};

#endif
