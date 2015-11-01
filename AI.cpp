#include "AI.h"

double AI::area(int x, int y) {
	int width = _game.getM() / 4;
	int height = _game.getN() / 4;

	int ox = _opPosition.first;
	int oy = _opPosition.second;

	int countMyBlocks = 0, countOpBlocks = 0;

	for (int dy = height; dy <= height; ++dy)
		for (int dx = width; dx <= width; ++dx)
			if (0 <= x + dx && x + dx < _game.getM() &&
				  0 <= y + dy && y + dy < _game.getN())
					++countMyBlocks;

	for (int dy = height; dy <= height; ++dy)
		for (int dx = width; dx <= width; ++dx)
			if (0 <= ox + dx && ox + dx < _game.getM() &&
				  0 <= oy + dy && oy + dy < _game.getN())
					++countOpBlocks;

		return (double)countMyBlocks / countOpBlocks;


double AI::survival(int x, int y) {
  int xStart = x - RADIUS + 1;
  int yStart = y - RADIUS + 1;
  int sum = 0;

  _danger.calculateEstimatedExplosionTime();

  for (int i = ystart; i < y + RADIUS; i++) {
    for (int j = xStart; j < x + RADIUS; j++) {
      if (i < 0 || j < 0 || i >= _game._N || j >= _game._M) {
        continue;
      }

      sum += 11 - _danger.getEstimatedExplosionTime(j, i);
    }
  }

  return (double)sums / RADIUS * RADIUS;
}
