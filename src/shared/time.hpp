//
// Created by Albert on 18/2/2016.
//

#ifndef CRANK_TIME_HPP
#define CRANK_TIME_HPP

#include <iostream>
#include <time.h>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

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
                        Time( const std::string& );
                        ~Time();

    void	            PrintTime();
    void	            SetTimestamp( const std::string& );
    unsigned long int	GetTimestampMilliseconds();


private:
    unsigned long int	timestamp_;


};

} // namespace ws


#endif //CRANK_TIME_HPP
