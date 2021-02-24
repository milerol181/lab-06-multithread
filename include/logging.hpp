//
// Created by milerol on 21.02.2021.
//

#ifndef LAB_06_MULTITHREADS_LOGGING_HPP
#define LAB_06_MULTITHREADS_LOGGING_HPP
const unsigned ten_MiB = 10 * 1024 * 1024;
void init()
{

  const std::string format = "%TimeStamp% <%Severity%> (%ThreadID%): %Message%";

  auto sink_to_file = boost::log::add_file_log(
      boost::log::keywords::file_name = "logs/log_trace_%N.log",
      boost::log::keywords::rotation_size = ten_MiB,
      boost::log::keywords::format = format);
      sink_to_file->set_filter(
      boost::log::trivial::severity >= boost::log::trivial::trace);

  auto sink_to_console = boost::log::add_console_log(
      std::cout,
      boost::log::keywords::format = format);
      sink_to_console->set_filter(
      boost::log::trivial::severity >= boost::log::trivial::info);

  boost::log::add_common_attributes();


}
#endif  // LAB_06_MULTITHREADS_LOGGING_HPP
