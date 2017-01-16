//
//  time.h
//  Sorting
//
//  Created by Julianne Salah on 10/25/15.
//  Copyright (c) 2015 Julianne Salah. All rights reserved.
//

#ifndef Sorting_time_h
#define Sorting_time_h

/****************************************************************************
 *                                                                          *
 *                   class ProcessTimer definition                          *
 *                                                                          *
 ****************************************************************************/

class ProcessTimer
{
    friend std::ostream& operator<<(std::ostream&, const ProcessTimer&);
    
private:
    clock_t timeStart; //start time
    clock_t timeEnd; //end time
    
public:
    ProcessTimer();
    ProcessTimer(clock_t);
    ~ProcessTimer();
    void setTimeStart(clock_t);
    void setTimeEnd(clock_t);
    clock_t getTimeStart();
    clock_t getTimeEnd();
    clock_t getTimeElapsed();
    
}; //end class ProcessTimer

/****************************************************************************
 **                                                                        **
 **                  class ProcessTimer implementation                     **
 **                                                                        **
 ****************************************************************************/

ProcessTimer::ProcessTimer()
{
    timeStart = 0;
    timeEnd = 0;
}

ProcessTimer::ProcessTimer(clock_t tmSt)
{
    timeStart = tmSt;
    timeEnd = 0;
}

ProcessTimer::~ProcessTimer()
{
    std::cout << "Inside destructor for ProcessTimer object" << std::endl;
}

std::ostream& operator<<(std::ostream &os, const ProcessTimer &tmStmp)
{
    std::cout << "Start time:\t" << tmStmp.timeStart << "\n";
    std::cout << "End time:\t" << tmStmp.timeEnd << "\n";
    std::cout << "Elapsed time:\t"
    << (tmStmp.timeEnd - static_cast<double>(tmStmp.timeStart))/(CLOCKS_PER_SEC/1000);
    std::cout << "\n";
    std::cout << std::endl;
    
    return os;
}

void ProcessTimer::setTimeStart(clock_t tmStart)
{
    timeStart = tmStart;
}

void ProcessTimer::setTimeEnd(clock_t tmEnd)
{
    timeEnd = tmEnd;
}


clock_t ProcessTimer::getTimeStart()
{
    return timeStart;
}

clock_t ProcessTimer::getTimeEnd()
{
    return timeEnd;
}


clock_t ProcessTimer::getTimeElapsed()
{
    return (timeEnd - static_cast<double>(timeStart))/(CLOCKS_PER_SEC/1000);
}

#endif
