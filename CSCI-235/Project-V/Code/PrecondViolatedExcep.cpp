//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing 7-6.
    @file PrecondViolatedExcep.cpp */

//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 14 July 2022
//  CSCI 235 Project - V

#include "PrecondViolatedExcep.hpp"

PrecondViolatedExcep::PrecondViolatedExcep(const std::string& message)
         : std::logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.

