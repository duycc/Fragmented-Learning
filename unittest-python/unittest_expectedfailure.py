# -*- coding: utf-8 -*-
"""
 * @file     unittest_expectedfailure.py
 * @brief    
 * @author   YongDu
 * @date     2022-03-31
"""
import unittest


class Test(unittest.TestCase):
    @unittest.expectedFailure
    def test_never_passes(self):
        self.assertTrue(False)

    @unittest.expectedFailure
    def test_always_passes(self):
        self.assertTrue(True)
