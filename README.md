# 🌐 TCP Client-Server in C

A minimal, clean implementation of a **TCP client-server** communication model written in C using POSIX sockets.

---

## 📖 Overview

This project demonstrates the fundamentals of **socket programming** in C. The server listens for incoming connections and sends a greeting message to the client. The client connects to the server, receives the message, and prints it.

```
[ Client ]  ──── connect() ────►  [ Server ]
           ◄──── send()    ────    "Hello! from Server here :)"
```

---

## 📁 Project Structure

```
tcp-client-server/
│
├── tcpserver.c      # TCP server — binds, listens, accepts, sends
└── tcpclient.c      # TCP client — connects, receives, prints
```

---

## ⚙️ How It Works

### Server (`tcpserver.c`)
1. Creates a TCP socket
2. Binds to port **4926** on all interfaces (`INADDR_ANY`)
3. Listens for incoming connections
4. Accepts a client connection
5. Sends the message `"Hello! from Server here :)"` to the client
6. Closes the connection

### Client (`tcpclient.c`)
1. Creates a TCP socket
2. Connects to `127.0.0.1` on port **4926**
3. Receives the message from the server
4. Prints it to the terminal
5. Closes the connection

---

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- Linux / macOS (or any POSIX-compatible OS)

### Compilation

```bash
# Compile the server
gcc tcpserver.c -o tcpserver

# Compile the client
gcc tcpclient.c -o tcpclient
```

### Running

> ⚠️ **Start the server first**, then run the client in a separate terminal.

**Terminal 1 — Start the server:**
```bash
./tcpserver
```

**Terminal 2 — Run the client:**
```bash
./tcpclient
```

### Expected Output

```
Client Received: Hello! from Server here :)
```

---

## 🔧 Configuration

| Parameter   | Value       | Location        |
|-------------|-------------|-----------------|
| IP Address  | `127.0.0.1` | `tcpclient.c`   |
| Port        | `4926`      | Both files      |
| Protocol    | TCP (IPv4)  | Both files      |

To change the port, update `htons(4926)` in both `tcpserver.c` and `tcpclient.c`.

---

## 📚 Concepts Covered

- **BSD Sockets API** — `socket()`, `bind()`, `listen()`, `accept()`, `connect()`
- **TCP (Transmission Control Protocol)** — reliable, connection-oriented communication
- **IPv4 addressing** — using `sockaddr_in` and `inet_pton()`
- **Client-Server model** — foundational architecture for networked applications

---

## 📜 License

This project is open source and available under the [MIT License](LICENSE).

---

<p align="center">Made with ❤️ in C by Jyotiraditya Rakshit</p>
