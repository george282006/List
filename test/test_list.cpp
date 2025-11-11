#include "list.h"
#include "gtest.h"

TEST(List, can_push_front_and_front_returns_correct_value)
{
    List<int> lst;
    lst.push_front(10);
    ASSERT_EQ(lst.front(), 10);
}

TEST(List, can_pop_front)
{
    List<int> lst;
    lst.push_front(5);
    lst.push_front(10);
    lst.pop_front();
    ASSERT_EQ(lst.front(), 5);
}

TEST(List, pop_front_on_empty_does_not_throw)
{
    List<int> lst;
    ASSERT_NO_THROW(lst.pop_front());
}

TEST(List, front_throws_on_empty)
{
    List<int> lst;
    ASSERT_ANY_THROW(lst.front());
}

TEST(List, clear_makes_list_empty)
{
    List<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    lst.clear();
    ASSERT_TRUE(lst.empty());
    ASSERT_EQ(lst.size(), 0);
}

TEST(List, size_is_correct_after_push_and_pop)
{
    List<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    ASSERT_EQ(lst.size(), 3);
    lst.pop_front();
    ASSERT_EQ(lst.size(), 2);
}

TEST(List, can_insert_after)
{
    List<int> lst;
    lst.push_front(1);
    auto it = lst.begin();
    lst.insert_after(it, 2);
    ++it;
    ASSERT_EQ(*it, 2);
    ASSERT_EQ(lst.size(), 2);
}

TEST(List, can_erase_after)
{
    List<int> lst;
    lst.push_front(3);
    lst.push_front(2);
    lst.push_front(1);
    auto it = lst.begin();
    lst.erase_after(it);
    ++it;
    ASSERT_EQ(*it, 3);
    ASSERT_EQ(lst.size(), 2);
}

TEST(List, erase_after_throws_if_invalid_iterator)
{
    List<int> lst;
    lst.push_front(1);
    auto it = lst.begin();
    ASSERT_ANY_THROW(lst.erase_after(it));
    ASSERT_ANY_THROW(lst.erase_after(it));
}

TEST(List, findkelemfte_returns_correct_elements)
{
    List<int> lst;
    for (int i = 5; i >= 1; --i)
        lst.push_front(i);

    ASSERT_EQ(lst.findkelemfte(1), 5);
    ASSERT_EQ(lst.findkelemfte(2), 4);
    ASSERT_EQ(lst.findkelemfte(5), 1);
}

TEST(List, findkelemfte_throws_if_k_too_large)
{
    List<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    ASSERT_ANY_THROW(lst.findkelemfte(5));
}

TEST(List, findkelemfte_throws_if_list_empty)
{
    List<int> lst;
    ASSERT_ANY_THROW(lst.findkelemfte(1));
}
