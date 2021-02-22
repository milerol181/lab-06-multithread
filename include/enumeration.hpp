//
// Created by milerol on 19.02.2021.
//

#ifndef LAB_06_MULTITHREADS_ENUMERATION_HPP
#define LAB_06_MULTITHREADS_ENUMERATION_HPP
#include <atomic>
#include <boost/log/trivial.hpp>
#include <cstdlib>
#include <picosha/picosha2.h>
#include <vector>
#include <iostream>
#include <string>
#include <thread>
#include <boost/lexical_cast.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/utility/setup.hpp>
#include <csignal>

bool work = true;


void enumeration() {
  const std::string null_string = "0000";
  while (work)
  {
    std::string input_rand = std::to_string(std::rand());
    std::string hash_key = picosha2::hash256_hex_string(input_rand);
    if (hash_key.substr(hash_key.size() - null_string.size()) ==
        null_string) {
      BOOST_LOG_TRIVIAL(info) << std::endl
                              << "!found value: ["
                              << input_rand
                              << "] hash is ["
                              << hash_key << "] !"
                              << std::endl;
    } else {
      BOOST_LOG_TRIVIAL(trace) << std ::endl
                               << "!found value ["
                               << input_rand
                               << "] hash is ["
                               << hash_key << "] !"
                               << std::endl;
    }
  }

}
#endif  // LAB_06_MULTITHREADS_ENUMERATION_HPP
