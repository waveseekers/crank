//
// Created by Albert on 18/2/2016.
//

#include "time.hpp"

using namespace ws;

/**
 * Time constructor
 *
 */
Time::Time( const std::string &datetime )
{
    SetTimestamp(datetime);
};

Time::~Time()
{
    // destructor
}

/**
 * Prints out the current time.
 *
 */
void
Time::SetTimestamp( const std::string &datetime )
{
//    const boost::posix_time::ptime time = boost::posix_time::time_from_string("1981-08-20 08:05:00");
    boost::posix_time::ptime t(boost::posix_time::time_from_string(datetime));
    boost::posix_time::ptime start(boost::gregorian::date(1970,1,1));
    boost::posix_time::time_duration time_diff = t - start;
    timestamp_ = time_diff.total_milliseconds();
}


/**
 * Returns the Unix timestamp in milliseconds for the date object.
 *
 * @return timestamp (milliseconds).
 */
unsigned long int
Time::GetTimestampMilliseconds()
{
    return timestamp_;
}


/**
 * Prints out the current time.
 *
 */
void
Time::PrintTime()
{
    std::cout << "It's beer o' clock!" << std::endl;
}
