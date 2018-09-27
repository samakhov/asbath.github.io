#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct point {
	int x;
	int y;
};

int plus_grand_rectangle(int hauteur, int longueur, int nombrePoints, struct point tabPoints[]) {
	int surface = 1;
	int hauteur_min = hauteur;

	int i,j,k;

	for (i = 0; i < nombrePoints; i++) {
		for (j = 0; j < nombrePoints; j++) {
			if (tabPoints[i].x<tabPoints[j].x) {
				for (k = 0; k < nombrePoints; k++) {
					if (tabPoints[i].x < tabPoints[k].x && tabPoints[k].x < tabPoints[j].x) {
						hauteur_min = tabPoints[k].y<hauteur_min?tabPoints[k].y:hauteur_min;
					}
				}
				surface = ((tabPoints[j].x - tabPoints[i].x) * hauteur_min) > surface ? ((tabPoints[j].x - tabPoints[i].x) * hauteur_min):surface;	
			}
		}
	}


	return surface;
}

int main() {

	struct point points[5];
	points[0].x = 2;
	points[0].y = 5;

	points[1].x = 5;
	points[1].y = 17;

	points[2].x = 11;
	points[2].y = 4;

	points[3].x = 16;
	points[3].y = 6;

	points[4].x = 20;
	points[4].y = 1;

	int res = plus_grand_rectangle(20, 25, 5, points);

	printf("%d\n", res);

	return 0;
}
