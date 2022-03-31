# -*- coding: utf-8 -*-
"""
 * @file     unittest_almostequal.py
 * @brief    
 * @author   YongDu
 * @date     2022-03-31
"""
import unittest


class AlmostEqualTest(unittest.TestCase):
    def test_equal(self):
        self.assertEqual(1.1, 3.3 - 2.2)

    def test_almost_equal(self):
        self.assertAlmostEqual(1.1, 3.3 - 2.2, places=1)

    def test_not_almost_equal(self):
        self.assertNotAlmostEqual(1.1, 3.3 - 2.0, places=1)
