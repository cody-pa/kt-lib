/// Result
///
/// This class is used when a function that returns some value has a
/// possibility of failure. The class requires the user to pass two
/// lambda functions to access the contents; The first lambda
/// is to contain code to be executed in the case of a failure, and
/// receives no value. The second lambda will be passed the value
/// that was meant to be received and the user may execute code
/// to use it there.

template <class T>
class Result
{
public:
    /// If passed a value on construction, then the operation was a success.
    Result(T data)
    {
        this->success = true;
        this->data = data;
    }
    /// Otherwise, the operation was a failure.
    Result()
    {
        this->success = false;
    }
    /// Simply returns whether the result was a success as a boolean value.
    inline bool succeeded()
    {
        return this->success;
    }

    /// The use must call this function to actually access the 
    /// stored data of the result.
    template <class Fail, class Success>
    auto use_result(Fail fail_action, Success success_action)
    {
        /// The first lambda is executed if the 
        /// result is a failure, and the expected data is not passed.
        if (!success)
        {
            return fail_action();
        }
        /// The second lambda receives the value the user expects,
        /// and is only executed if the result is a success.
        else
        {
            return success_action(data);
        }
    }
private:
    bool success;
    T data;
};