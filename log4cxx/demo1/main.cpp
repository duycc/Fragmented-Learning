#include <iostream>
#include <log4cxx/logger.h>
#include <log4cxx/logstring.h>
#include <log4cxx/propertyconfigurator.h>

using namespace log4cxx;

void test() {
  PropertyConfigurator::configure("./log.properties");
  LoggerPtr rootLogger = Logger::getRootLogger();

  LOG4CXX_TRACE(rootLogger, "TRACE");
  LOG4CXX_DEBUG(rootLogger, "DEBUG");
  LOG4CXX_WARN(rootLogger, "WARN");
  LOG4CXX_ERROR(rootLogger, "ERROR");
}

int main() {
  test();
  return 0;
}