#include <iostream>
#include <map>
#include <mutex>
#include <memory>

std::mutex mtx;

int main(int argc, char **argv)
{
    /*****************************************************/

    // For the iterator search
    std::map<char, int32_t> character_map{
        {'c', 100},
        {'d', 101},
        {'e', 102}
    };
    if (auto itr{character_map.find('c')}; itr != character_map.end())
    {
        // *itr is ok
    }
    else
    {
        // itr is pointing to the end
    }
    // itr is undefined

    /*****************************************************/

    // For the lock guard
    if (std::lock_guard<std::mutex> lock(mtx); true) {
        // lock protected task
    } // end of the lock


    /*****************************************************/

    // For the shared pointers
    auto pointer = std::shared_ptr<int>(new int(42));
    std::weak_ptr<int> weak_pointer = pointer;
    if (auto shared_pointer(weak_pointer.lock()); shared_pointer != nullptr)
    {
        // some actions
    }

    return 0;
}