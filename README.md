Crank
=====

An example CMake starter project featuring the following includes:

- [DataStax C/C++ Driver](https://github.com/datastax/cpp-driver) for Apache Cassandra
- [Boost C++ Libraries](http://www.boost.org/)

## Getting started

The dependencies for the project, as stated above, are the C/C++ driver for Apache Cassandra and the Boost libraries.
These instructions assume your environment is Mac OS X. Instructions for other environments will be provided later.

Prior to building the Cassandra driver, install its dependencies. Note OpenSSL requires additional configuration before
buidling the driver:

```
brew install libuv cmake
brew install openssl
brew link --force openssl
```

Build the driver:

```
git clone https://github.com/datastax/cpp-driver.git
mkdir cpp-driver/build
cd cpp-driver/build
cmake ..
make
```

Copy the built libraries to a shared library directory, usually `/usr/lib` or a custom location `/opt/cassandra`:

```
sudo rsync -avP libcass* /opt/cassandra
```

## Project structure

```
crank/
├── cmake/
│   └── modules/
│       └── FindCassandra.cmake
├── src/
│   ├── common/
│   └── main.cpp
└── test/
```