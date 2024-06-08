/*
 * Filename: main.cc
 * Created on: June  7, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include <iostream>

#include "config.h"
#include "log_manager.h"

int main(int argc, char* argv[])
{
    LogManager& logger = LogManager::GetInstance();

    logger.Log("Hello, World!", spdlog::level::info);

    return EXIT_SUCCESS;
}
