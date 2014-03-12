// This file is part of RFUS (Rich's Fast Userspace Scheduling)
// RFUS is licensed under the MIT LICENSE. See the LICENSE file for more info.

#pragma once

#include <functional>
#include <cstdint>
#include <vector>

namespace rfus
{

/// Forward Declarations
struct join_semaphore_t;

/**
* Structure used in the actual RFUS implementation.
*/
struct task_t
{
    task_t(std::function<void()> action, uint64_t deadline, size_t worker);
    ~task_t();    

    // User vars
    std::function<void()> action;
    uint64_t priority;

    // Book keeping
    task_t* continuation;
    join_semaphore_t* join;
    size_t worker;

    task_t *next;
};

}
