# -*- coding: utf-8 -*-
import logging

# ------------------------------------------------------------------------------
#   logging提供的模块级别的函数
# ------------------------------------------------------------------------------

# LOG_FORMAT = "%(asctime)s - %(levelname)s - %(message)s"
# DATE_FORMAT = "%m/%d/%Y %H:%M:%S %p"
# logging.basicConfig(filename="my.log", level=logging.DEBUG, format=LOG_FORMAT, datefmt=DATE_FORMAT)

# logging.debug("This is a debug log")
# logging.info("This is a info log")
# logging.warning("This is a warning log")
# logging.error("This is a error log")
# logging.critical("This is a critical log")

# LOG_FORMAT = "%(asctime)s - %(levelname)s - %(user)s[%(ip)s] - %(message)s"
# DATE_FORMAT = "%m/%d/%Y %H:%M:%S %p"
# logging.basicConfig(format=LOG_FORMAT, datefmt=DATE_FORMAT)
# logging.warning(
#     "Some one delete the log file", exc_info=True, stack_info=True, extra={"user": "Tom", "ip": "127.0.0.1"}
# )

LOG_FORMAT = "%(levelname)s %(asctime)s %(filename)s:%(lineno)d _msg=%(message)s"
logging.basicConfig(format=LOG_FORMAT)
logging.warning("[test_logging] test err")
