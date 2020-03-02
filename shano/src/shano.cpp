// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest

#include "shano.h"
#include "ShannonFano.h"
#include "spdlog/spdlog.h"

std::string shano::echo(const std::string& text)
{
    return "Hi, " + text;
}


std::string shano::addSequence(const std::string& sequence)
{
    spdlog::info("Enter in shano ");
    ShannonFano shannonFano = ShannonFano(sequence);
    std::string compresed = shannonFano.Encode();

    return compresed;
}

