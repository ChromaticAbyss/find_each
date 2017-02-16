#include "stdafx.h"
#include "CppUnitTest.h"

#include "../KnuthMorrisPratt/KMP.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Find_at_start)
		{
			std::string a = "abccccc";
			std::string b = "abc";
			auto c = find_each::find_each(a.begin(), a.end(), b.begin(), b.end());
			Assert::IsTrue((int)c.size() == 1, L"message", LINE_INFO());
			Assert::IsTrue(a.begin() == c[0], L"message", LINE_INFO());
		}

		TEST_METHOD(Find_at_end)
		{
			std::string a = "cccccab";
			std::string b = "ab";
			auto c = find_each::find_each(a.cbegin(), a.cend(), b.cbegin(), b.cend());
			Assert::IsTrue((int)c.size() == 1, L"message", LINE_INFO());
			Assert::IsTrue(*(c[0]) == 'a', L"message", LINE_INFO());
		}

		TEST_METHOD(Find_at_end_cutoff)
		{
			std::string a = "cccccab";
			std::string b = "abc";
			auto c = find_each::find_each(a.cbegin(), a.cend(), b.cbegin(), b.cend());
			Assert::IsTrue((int)c.size() == 0, L"message", LINE_INFO());
		}

		TEST_METHOD(Find_two)
		{
			std::string a = "ccabccabcc";
			std::string b = "ab";
			auto c = find_each::find_each(a.cbegin(), a.cend(), b.cbegin(), b.cend());
			Assert::IsTrue((int)c.size() == 2, L"message", LINE_INFO());
			Assert::IsTrue(*(c[0]) == 'a', L"message", LINE_INFO());
			Assert::IsTrue(*(c[1]) == 'a', L"message", LINE_INFO());
		}


		TEST_METHOD(Find_two_overlapping)
		{
			std::string a = "ccabababccc";
			std::string b = "abab";
			auto c = find_each::find_each(a.cbegin(), a.cend(), b.cbegin(), b.cend());
			Assert::IsTrue((int)c.size() == 2, L"message", LINE_INFO());
			Assert::IsTrue(*(c[0]) == 'a', L"message", LINE_INFO());
			Assert::IsTrue(*(c[1]) == 'a', L"message", LINE_INFO());
		}

		TEST_METHOD(Find_two_overlapping_off)
		{
			std::string a = "ccabababccc";
			std::string b = "abab";
			auto c = find_each::find_each(a.cbegin(), a.cend(), b.cbegin(), b.cend(), false);
			Assert::IsTrue((int)c.size() == 1, L"message", LINE_INFO());
			Assert::IsTrue(*(c[0]) == 'a', L"message", LINE_INFO());
		}

		TEST_METHOD(Find_after_cancel)
		{
			std::string a = "ccabababdc";
			std::string b = "ababd";
			auto c = find_each::find_each(a.cbegin(), a.cend(), b.cbegin(), b.cend());
			Assert::IsTrue((int)c.size() == 1, L"message", LINE_INFO());
			Assert::IsTrue(*(c[0]) == 'a', L"message", LINE_INFO());
		}

		TEST_METHOD(Find_vector_mixed_datatypes)
		{
			std::vector<int> a = { 0,0,0,0,1,2,3,0,0,1,2 };
			std::vector<float> b = { 1,2,3 };
			auto c = find_each::find_each(a.cbegin(), a.cend(), b.cbegin(), b.cend());
			Assert::IsTrue((int)c.size() == 1, L"message", LINE_INFO());
			Assert::IsTrue(*(c[0]) == 1, L"message", LINE_INFO());
		}

		TEST_METHOD(Find_mixed_containers)
		{
			std::list<double> a = { 0,0,0,0,1,2,3,0,0,1,2 };
			std::vector<float> b = { 1,2,3 };
			auto c = find_each::find_each(a.cbegin(), a.cend(), b.cbegin(), b.cend());
			Assert::IsTrue((int)c.size() == 1, L"message", LINE_INFO());
			Assert::IsTrue(*(c[0]) == 1.0, L"message", LINE_INFO());
		}

		TEST_METHOD(Find_no_match_on_wrong_order)
		{
			std::vector<float> a = { 0,0,0,0,1,2,3,0,0,1,2 };
			std::vector<float> b = { 1,2,3 };
			auto c = find_each::find_each(b.cbegin(), b.cend(),a.cbegin(), a.cend());
			Assert::IsTrue((int)c.size() == 0, L"message", LINE_INFO());
		}


	};
}