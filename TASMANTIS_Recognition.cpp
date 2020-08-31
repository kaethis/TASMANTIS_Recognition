#include "TASMANTIS_Recognition.h"


static void TASMANTIS_Recognition::enumerate(struct TASMANTIS_Lidar::scan *s, struct freq *f) { /* -----------------------------
* This STATIC FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    int dist;


    for (int i = 0; i < DIST_MAX; i++) f->counts[i] = 0;


    for (int i = 0; i < 360; i++) {

        dist = s->dists[i];

        if (dist >= DIST_MAX) dist = (DIST_MAX - 1);


        f->counts[dist]++;        
    }
}


static unsigned long TASMANTIS_Recognition::compare(struct freq *f1, struct freq *f2) { /* -------------------------------------
* This STATIC FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    int diff;

    unsigned long sum;


    sum = 0;

    for (int i = 0; i < DIST_MAX; i++) {

        diff = abs(f2->counts[i] - f1->counts[i]);

        sum += diff;
    }


    return sum;
}


static int TASMANTIS_Recognition::reorient(struct TASMANTIS_Lidar::scan *s1, struct TASMANTIS_Lidar::scan *s2) { /* ------------
* This STATIC FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    int diff,

        deg;

    unsigned long sum,

                  sum_min;


    sum = 0;

    for (int i = 0; i < 360; i++) {

        diff = abs(s1->dists[i] - s2->dists[(i + 0) % 360]);

        sum += diff;
    }
  
    sum_min = sum;

    deg = 0;
 
 
    for (int i = 1; i < 360; i++) {

        sum = 0;
 
        for (int j = 0; j < 360; j++) {

            diff = abs(s1->dists[j] - s2->dists[(j + i) % 360]);

            sum += diff;
        }


        if (sum < sum_min) {

            sum_min = sum;

            deg = i;
        }
    }


    return deg;
}
