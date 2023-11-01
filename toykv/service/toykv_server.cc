#include "toykv_server.h"

#include <thrift/concurrency/ThreadFactory.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TServerTransport.h>

static constexpr int threadNum = 10;

using Processor = apache::thrift::TProcessor;

using ServerTransport = apache::thrift::transport::TServerTransport;
using ServerSocket = apache::thrift::transport::TServerSocket;

using TransportFactory = apache::thrift::transport::TTransportFactory;
using BufferedTransportFactory = apache::thrift::transport::TBufferedTransportFactory;
using ProtocolFactory = apache::thrift::protocol::TProtocolFactory;
using BinaryProtocolFactory = apache::thrift::protocol::TBinaryProtocolFactory;

using ThreadManager = apache::thrift::concurrency::ThreadManager;
using ThreadFactory = apache::thrift::concurrency::ThreadFactory;

using ThreadedServer = apache::thrift::server::TThreadedServer;

namespace toykv {

ToykvServerUPtr ToykvServer::CreateToykvServer(storagePtr storage, int port) {
    std::shared_ptr<ToykvService> service(new ToykvService(storage));
    std::shared_ptr<Processor> processor(new ToykvServiceProcessor(service));

    std::shared_ptr<ServerTransport> serverTransport(new ServerSocket(port));
    std::shared_ptr<TransportFactory> transportFactory(new BufferedTransportFactory());
    std::shared_ptr<ProtocolFactory> protocolFactory(new BinaryProtocolFactory());

    std::shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(threadNum);
    std::shared_ptr<ThreadFactory> threadFactory(new ThreadFactory());
    threadManager->threadFactory(threadFactory);
    threadManager->start();

    std::shared_ptr<ThreadedServer> server(new ThreadedServer(
            processor, serverTransport, transportFactory, protocolFactory, threadFactory));
    ToykvServer tServer(server);

    return std::make_unique<ToykvServer>(server);
}

} // namespace toykv