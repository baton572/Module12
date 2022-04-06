#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>

class Node
{
public:
    Node(int data) : m_data(data), m_next(nullptr) {}
    int m_data;
    Node* m_next;
};

class List
{
public:
    List() : m_head(nullptr) {}
    void push_back(int data);
    void show();
    void deleteNode(int position);
    void clear();

private:
    Node* m_head;
};

//#define MAX 1000
//
//class Stack
//{
//public:
//    Stack() : m_top(-1) {}
//    bool push(int x);
//    int  pop();
//    int  peek();
//    bool isFull();
//    bool isEmpty();
//
//    int m_items[MAX];
//
//private:
//    int m_top;
//};

void List::push_back(int data)
{
    // создаем новый узел
    Node* node = new Node(data);
    // если список пуст, возвращаем узел
    if (m_head == nullptr)
    {
        m_head = node;
        return;
    }
    // в цикле ищем последний элемент списка
    Node* last = m_head;
    while (last->m_next != nullptr)
    {
        last = last->m_next;
    }
    // Обновляем указатель next последнего узла на указатель на новый узел
    last->m_next = node;
    return;
}

void List::show()
{
    auto node = m_head;
    //
    while (node != nullptr)
    {
        std::cout << node->m_data << std::endl;
        node = node->m_next;
    }
    std::cout << std::endl;
}

void List::deleteNode(int position)
{
    if (m_head && (position >= 0))
    {
        auto nodetAddr = &m_head;
        auto curPosition = 0;
        //
        do
        {
            if (position != curPosition)
                nodetAddr = &((*nodetAddr)->m_next);
            else
            {
                auto p = *nodetAddr;
                *nodetAddr = (*nodetAddr)->m_next;
                //
                delete p;
                break;
            }
            //
            ++curPosition;
        } while (*nodetAddr != nullptr);
    }
}

void List::clear()
{
    auto node = m_head;
    m_head = nullptr;
    //
    while (node != nullptr)
    {
        auto p = node;
        node = node->m_next;
        //
        delete p;
    }
}

//class Stack
//{
//public:
//    bool push(int x);
//    int  pop();
//    int  peek();
//    bool isEmpty();
//
//private:
//    Node* m_root = nullptr;
//};
//
//bool Stack::isEmpty()
//{
//    return m_root == nullptr;
//}
//
//bool Stack::push(int x)
//{
//    auto node = new Node(x);
//    // если стек полон выводим сообщение на консоль и возвращаемся
//    if (!node)
//    {
//        std::cout << "Stack Overflow";
//        return false;
//    }
//    else // кладем на вершину стека данные
//    {
//        node->m_next = m_root;
//        m_root = node;
//        return true;
//    }
//}
//
//int Stack::pop()
//{
//    // если стек пуст, выводим сообщение и возращаем значение 0
//    if (!m_root)
//    {
//        std::cout << "Stack Underflow";
//        return 0;
//    }
//    else // забираем значение вершины стека
//    {
//        int x = m_root->m_data;
//        //
//        auto p = m_root;
//        m_root = m_root->m_next;
//        delete p;
//        //
//        return x;
//    }
//}
//
//int Stack::peek()
//{
//    // если стек пуст, возвращаемся
//    if (!m_root)
//    {
//        std::cout << "Stack is Empty";
//        return 0;
//    }
//    else // возвращаем значение вершины стека без удаления данных
//    {
//        return m_root->m_data;
//    }
//}

#define MAX 1000

class Stack
{
private:
    int m_top;

public:
    char m_items[MAX];
    Stack() : m_top(-1) {}
    bool push(char x);
    char pop();
    char peek();
    bool isFull();
    bool isEmpty();
};

bool Stack::isEmpty()
{
    return m_top < 0;
}

bool Stack::isFull()
{
    return m_top >= (MAX - 1);
}

bool Stack::push(char x)
{
    // если стек полон выводим сообщение на консоль и возвращаемся
    if (isFull())
    {
        std::cout << "Stack Overflow";
        return false;
    }
    else
        // увеличиваем значение вершины стека и кладем на вершину стека данные
    {
        ++m_top;
        m_items[m_top] = x;
        return true;
    }
}

char Stack::pop()
{
    // если стек пуст, выводим сообщение и возращаем значение 0
    if (isEmpty())
    {
        std::cout << "Stack Underflow";
        return 0;
    }
    else
        // забираем значение вершины стека, уменьшаем значение вершины стек на 1 и возращаем значение
    {
        char x = m_items[m_top];
        --m_top;
        return x;
    }
}

char Stack::peek()
{
    // если стек пуст возвращаемся
    if (isEmpty()) {
        std::cout << "Stack is Empty";
        return 0;
    }
    else
        // возвращаем значение вершины стека без удаления данных
    {
        char x = m_items[m_top];
        return x;
    }
}

bool BracketsBalanced(std::string expr)
{
    bool ret = false;
    //
    Stack* stack = new Stack();
    if (stack)
    {
        //
        char* pChar = &expr[0];
        //
        while (*pChar != 0)
        {
            switch (*pChar)
            {
            case '[':
            {
                if (!stack->isFull())
                    stack->push(']');
                else
                    break;
            }
            break;
            case '(':
            {
                if (!stack->isFull())
                    stack->push(')');
                else
                    break;
            }
            break;
            case '{':
            {
                if (!stack->isFull())
                    stack->push('}');
                else
                    break;
            }
            break;
            //
            default:
            {
                if (!stack->isEmpty())
                {
                    char ch = stack->pop();
                    if ((ch == ']') || (ch == ')') || (ch == '}'))
                    {
                        if (*pChar != ch)
                            break;
                    }
                }
                else
                {
                    if ((*pChar == ']') || (*pChar == ')') || (*pChar == '}'))
                    {
                        stack->push('}');
                        break;
                    }
                }
            }
            }
            ++pChar;
        }
        if (stack->isEmpty())
            ret = true;
        //
        delete stack;
    }
    return ret;
}

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;

        if (arr[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    // if we reach here, then element was 
    // not present 
    return -1;
}

std::vector< std::string > topKFrequent(std::vector< std::string >& words, int k) {
    std::vector< std::string > ret;
    std::list< int > numbers;
    for (size_t i = 0; i < words.size(); ++i)
        numbers.push_back(i);
    //
    std::map< int, std::set< std::string >*> mFrequency;
    //
    while (numbers.size() > 0) {
        //
        auto it = numbers.begin();
        auto pCheckWord = &words[*it];
        it = numbers.erase(it);
        size_t q = 1;
        //
        while (it != numbers.end()) {
            auto p = &words[*it];
            if (*p == *pCheckWord) {
                ++q;
                it = numbers.erase(it);
            }
            else
                ++it;
        }
        
        std::set< std::string >* pSet;
        try {
            pSet = mFrequency.at(q);
        }
        catch (...) {
            pSet = new std::set< std::string >;
        }
        if (pSet) {
            pSet->insert(*pCheckWord);
            mFrequency[q] = pSet;
        }
    }
    if (mFrequency.size() > 0) {
        auto it = mFrequency.end();
        --it;
        while (k > 0) {
            auto itWord = it->second->begin();
            decltype (k) n = 0;
            for (decltype (k) i = 0; i < k; ++i) {
                ret.push_back(*itWord++);
                ++n;
                if (itWord == it->second->end())
                    break;
            }
            k -= n;
            if (it != mFrequency.begin())
                --it;
            else
                break;
        }

        for (auto it = mFrequency.begin(); it != mFrequency.end(); ++it)
            delete it->second;
    }
    //
    return ret;
}

void CalculateLPS(const std::string& s, int* lps)
{
    size_t i = 1;
    size_t j = 0;
    //
    while (i < s.size())
    {
        if (s[i] == s[j])
        {
            ++j;
            lps[i] = j;
            ++i;
        }
        else
        {
            if (j == 0)
            {
                lps[i] = 0;
                ++i;
            }
            else
                j = lps[j - 1];
        }
            
    }
}

void KMPSearch(const std::string& pat, const std::string& txt)
{
    int* lps = new int[pat.size()];

    CalculateLPS(pat, lps);

    size_t i = 0;
    size_t j = 0;
    while (i < txt.size())
    {
        if (pat[j] == txt[i])
        {
            ++j;
            ++i;
        }
        if (j == pat.size())
        {
            std::cout << "Found pattern at index " << i - j << std::endl;
            j = lps[j - 1];
        }
        else if (i < txt.size() && pat[j] != txt[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
                ++i;
        }
    }
}

# define NO_OF_CHARS 256  

void badCharHeuristic(std::string& str, int size, int badchar[NO_OF_CHARS])
{
    int i;

    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

void BMSearch(const std::string& txt, std::string& pat)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            std::cout << "pattern occurs at shift = " << s << std::endl;

            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

        }
        else
        {
            int bc = badchar[txt[s + j]];
            s += std::max(1, j - bc);
        }
    }
}

bool subArraySum(int arr[], int n, int sum)
{
    bool ret = false;
    decltype (sum) s = 0;
    //
    decltype (n) i = 0;
    while (i < n)
    {
        decltype (n) j = i;
        //
        for (j; j < n; ++j)
        {
            s += arr[j];
            //
            if (s >= sum)
                break;
        }
        //
        if (s == sum)
        {
            std::cout << i << ' ' << j << std::endl;
            //
            ret = true;
            break;
        }
        else if (s < sum)
            break;
        //
        s = 0;
        ++i;
    }
    //
    return ret;
}

bool IsKPeriodic(const std::string& s, int K)
{
    bool ret = false;
    //
    decltype (K) size = s.size();
    if (size > K)
    {
        decltype (size) i = 0;
        //
        std::string substrMain = s.substr(i, K);
        i += K;
        //
        while (i < size)
        {
            std::string substr = s.substr(i, K);
            if (substrMain != substr)
                break;
            //
            i += K;
        }
        //
        if (i == size)
            ret = true;
    }
    //
    return ret;
}

int main()
{
    //List* list = new List();
    ////
    //list->push_back(1);
    //list->push_back(2);
    //list->push_back(3);
    //list->push_back(4);
    //list->push_back(5);
    ////
    //list->show();
    ////
    //list->deleteNode(4);
    ////
    //list->show();
    ////
    //list->clear();
    ////
    //list->deleteNode(0);
    ////
    //delete list;

    //std::string s = "[{[(())]]]";

    //bool b = BracketsBalanced(s);

    //s = "[{[(())]}]";

    //b = BracketsBalanced(s);

    //s = "";

    //b = BracketsBalanced(s);

    //s = "[{[(())]}](";

    //b = BracketsBalanced(s);

    //int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    //auto i = binarySearch(array, 0, 10 - 1, 7);

    //std::vector< std::string > words = { "i", "love", "leetcode", "i", "love", "coding" };
    //int k = 4;

    //std::vector< std::string > out = topKFrequent(words, k);

    //std::string s = "ABCABEABCABCABDABCABEABCABCABD";
    std::string s = "abcabcabcabcabcabcabcabcabcabc";
    std::string sPart = "ABCABD";

    //int lps1[11] = { 0 };

    //KMPSearch(sPart, s);

    //BMSearch(s, sPart);

    ////int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //int array[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    bool b;

    //b = subArraySum(array, 10, 15);

    b = IsKPeriodic(s, 3);

    int ii = 1;
}
