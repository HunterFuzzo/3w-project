#ifndef RTC_H // Protection against multiple inclusions
#define RTC_H

#include "data_structures.h"
void setupRtc();
void logRtcData();
RtcData getRtcData(); // Declaration for the getRtcData function

#endif // RTC_H
