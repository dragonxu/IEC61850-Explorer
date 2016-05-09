# IEC61850-Explorer
=====
IEC61850 is a basic explorer for exploring, reading and writing values in IED servers.

Installation
------------

### Dependencies

- cmake
- libiec61850 (get it from http://libiec61850.com/)
- Qt5

### Building
```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```

### Testing

A simple test server (iec61850\_testsrv) is supplied for testing purposes.

Under linux, to allow the debug server to listen on port 102, users may install authbind and run:
```sh
$ sudo touch /etc/authbind/byport/102
$ sudo chown root:dialout /etc/authbind/byport/102
$ sudo chmod 711 /etc/authbind/byport/102
```

then you can run the server by launching :
```sh
$ authbind iec61850_testsrv
```

### Roadmap

- Improve shell version
- Allow variables modification

### Work in progress

- Allow authentication
- Add automatic refresh
