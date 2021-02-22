#include <enumeration.hpp>
#include "logging.hpp"
#include <thread>
#include <csignal>

void sig_handler(int sig)
{
  std::cout << "--------------------" << std::endl;
  std::cout << sig << std::endl << "STOPPED PROCESS";
  exit(0);
}

int main(int argc, char *argv[]) {
  signal(SIGINT, &sig_handler);
  std::cin.tie(nullptr);
    init();
    unsigned thread_count;
    if (argc >= 2) {thread_count = boost::lexical_cast<unsigned>(argv[1]);}
    else thread_count = std::thread::hardware_concurrency();

    BOOST_LOG_TRIVIAL(trace) << "THREADS COUNT" << thread_count;

    std::vector<std::thread> threads;
    threads.reserve(thread_count);
    for (unsigned i = 0; i < thread_count; i++) {
      threads.emplace_back(enumeration);
    }
    for (std::thread &thr : threads) {
      thr.join();
    }
    return 0;
  }

