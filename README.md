# Server-Client Communication

This repository contains simple server-client communication code.

## Requirements

- C compiler (e.g., gcc)
- POSIX-compliant operating system (Linux, Unix, macOS)
  
## UDP Protocol Communication

### Overview

The UDP (User Datagram Protocol) code enables communication between a client and a server using UDP sockets.  It demonstrates how to exchange messages between the client and server using UDP, highlighting UDP's connectionless and unreliable nature.
### Usage

To run the UDP server and client:

1. Compile the server and client code.
   ```bash
    gcc -o server_UDP.c udp_server.c
    gcc -o client_UDP.c udp_client.c
   ```
2. Run the server program.
   ```bash
   ./udp_server <port>
   ```
   Example:
   ```bash
   ./udp_server 5555
   ```
3. Run the client program
   ```bash
   ./udp_client <server address> <port>
   ```
   Example:
   ```bash
   ./udp_client 127.0.0.1 5555
   ```
## TCP Protocol Communication

### Overview

The TCP (Transmission Control Protocol) code facilitates communication between a client and server using TCP sockets. It demonstrates a simple client-server interaction over TCP, emphasizing TCP's reliability and connection-oriented nature.

### Usage

To run the TCP server and client:

1. Compile the server and client code.
   ```bash
    gcc -o server_TCP.c tcp_server.c
    gcc -o client_TCP.c tcp_client.c
   ```
2. Run the server program.
   ```bash
   ./tcp_server <port>
   ```
   Example:
   ```bash
   ./tcp_server 5555
   ```
3. Run the client program
   ```bash
   ./tcp_client <port>
   ```
   Example:
   ```bash
   ./tcp_client 5555
   ```
