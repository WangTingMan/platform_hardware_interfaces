#pragma once
#include <functional>

class bluetooth_audio_interface
{

public:

    using async_task_type = std::function<void()>;
    using async_task_scheduler_type = std::function<void(async_task_type, int)>;

    virtual ~bluetooth_audio_interface(){}

    virtual int init() = 0;

    virtual void stop() = 0;

    virtual void release() = 0;

    virtual void start_stream() = 0;

    virtual void stop_stream() = 0;

    virtual void suspend_stream() = 0;

    virtual void request_presentaion_delay() = 0;

    virtual bool is_enabled() = 0;

    virtual void register_async_task_scheduler(async_task_scheduler_type) = 0;

    virtual void test() = 0;
};

