//
// Created by Albert on 18/2/2016.
//

#ifndef CRANK_TIME_HPP
#define CRANK_TIME_HPP

#include <iostream>
#include <time.h>

static const int SESSION_SHARD_INTERVAL = 3600000; // 1 hour in milliseconds

namespace ws
{

/*****************************************************************************
 *
 * Time class
 *
 *****************************************************************************/
class Time
{
public:
    Time();
    ~Time();

    void	    PrintTime();

};

} // namespace ws


#endif //CRANK_TIME_HPP
