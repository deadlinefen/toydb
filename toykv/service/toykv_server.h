#pragma once

#include <thrift/concurrency/ThreadFactory.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TNonblockingServerSocket.h>

#include <memory>

#include "toykv_service.h"
#include "utils/status.h"

namespace toykv {

class ToykvServer;
using ToykvServerUPtr = std::unique_ptr<ToykvServer>;

class ToykvServer {
    using ServerPtr = std::shared_ptr<apache::thrift::server::TThreadedServer>;

public:
    static ToykvServerUPtr CreateToykvServer(storagePtr storage, int port);
    ToykvServer(ServerPtr server) : _server(server) {}
    ~ToykvServer() = default;

    inline void Start() { _server->serve(); }

private:
    ServerPtr _server;
};

} // namespace toykv
