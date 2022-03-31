# -*- coding: utf-8 -*-


from audioop import mul
import unittest
from mathfunc import *


class TestMathFunc(unittest.TestCase):
    # def setUp(self) -> None:
    #     print("do something before test, Prepare ennvironment.")

    # def tearDown(self) -> None:
    #     print("do something after test, Clean up.")

    @classmethod
    def setUpClass(cls) -> None:
        print("setUpClass() called.")

    @classmethod
    def tearDownClass(cls) -> None:
        print("tearDownClass() called.")

    def test_add(self):
        """Test method add(a, b)"""
        self.assertEqual(3, add(1, 2))
        self.assertNotEqual(3, add(2, 2))

    def test_minus(self):
        """Test method minus(a, b)"""
        self.assertEqual(1, minus(3, 2))

    def test_multi(self):
        """Test method multi(a, b)"""
        self.assertEqual(6, multi(2, 3))

    # @unittest.skip("I don't want to run this case.")
    def test_divide(self):
        """Test method divide(a, b)"""
        self.skipTest("Don't run this.")
        self.assertEqual(2, divide(6, 3))
        self.assertEqual(2.5, divide(5, 2))


if __name__ == '__main__':
    unittest.main(verbosity=2)
