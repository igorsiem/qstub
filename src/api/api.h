/**
 * \file api.h
 * Header file for a stub api
 * 
 * \author Igor Siemienowicz
 * 
 * \copyright Copyright Igor Siemienowicz 2018 Distributed under the Boost
 * Software License, Version 1.0. (See accompanying file ../LICENSE_1_0.txt
 * or copy at https://www.boost.org/LICENSE_1_0.txt
 */

#include <string>

#ifndef _api_api_h_included
#define _api_api_h_included

/**
 * Declarations for the Application Programming Interface to the core logic
 */
namespace api {

/**
 * Retrieve the version string for hte library
 */
extern std::string version(void);

extern std::wstring wversion(void);

}   // end api namespace

#endif
