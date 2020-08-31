#ifndef _TASMANTIS_RECOGNITION_H_

#define _TASMANTIS_RECOGNITION_H_


#include <Arduino.h>

#include "TASMANTIS_Recognition.h"

#include "TASMANTIS_Lidar.h"


class TASMANTIS_Recognition { /* -----------------------------------------------------------------------------------------------
* This CLASS ...
* --------------------------------------------------------------------------------------------------------------------------- */

  public:

    const static int DIST_MAX = 500;    // cm


    struct freq {

        uint8_t counts[DIST_MAX] = { 0 };
    };


    static void enumerate(struct TASMANTIS_Lidar::scan*, struct freq*);

    static unsigned long compare(struct freq*, struct freq*);

    static int reorient(struct TASMANTIS_Lidar::scan*, struct TASMANTIS_Lidar::scan*);


  private:

};


#endif /* _TASMANTIS_RECOGNITION_H_ */
