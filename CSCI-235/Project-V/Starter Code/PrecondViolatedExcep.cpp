/** Listing 7-6.
    @file PrecondViolatedExcep.cpp */
#include "PrecondViolatedExcep.hpp"

PrecondViolatedExcep::PrecondViolatedExcep(const std::string& message)
         : std::logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.

