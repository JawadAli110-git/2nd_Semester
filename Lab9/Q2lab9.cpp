#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

enum class Severity {
    INFO, WARNING, ERROR
};

class Logger {
private:
    deque<string> logs;
    const size_t MAX_LOGS = 1000;

    string formatMessage(const string& module, Severity level, const string& message) {
        string prefix;
        switch (level) {
            case Severity::INFO:    prefix = "[INFO]"; break;
            case Severity::WARNING: prefix = "[WARNING]"; break;
            case Severity::ERROR:   prefix = "[ERROR]"; break;
        }
        return prefix + " [" + module + "]: " + message;
    }

    void storeLog(const string& log) {
        if (logs.size() >= MAX_LOGS) {
            logs.pop_front(); // Remove oldest
        }
        logs.push_back(log);
    }

    // Singleton pattern (optional for global access)
    Logger() {} // private constructor

public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const string& module, Severity level, const string& message) {
        string formatted = formatMessage(module, level, message);
        storeLog(formatted);
    }

    // Friend class for audit access
    friend class Auditor;
};

class Auditor {
private:
    string password;

public:
    Auditor(const string& pass) : password(pass) {}

    vector<string> retrieveLogs() {
        if (password == "secure123") {
            Logger& logger = Logger::getInstance();
            return vector<string>(logger.logs.begin(), logger.logs.end()); // Safe copy
        } else {
            cout << "Unauthorized access attempt!\n";
            return {};
        }
    }
};
