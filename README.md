# Bud

## Build

Preparing:
```
svn co http://gyp.googlecode.com/svn/trunk build/gyp
```

Building:
```
./gyp_bud
make -C out/
```

The result will be located at: `./out/Release/bud`.

## Running

Bud is using [JSON][0] as a configuration format. Run `bud --default-config`
to get default configuration options (with comments and description below):

```javascript
{
  // Spawn detached "daemon" process
  "daemon": false,

  // Number of workers to use, if 0 - only one process will be spawned.
  "workers": 1,

  // Timeout after which workers will be restarted (if they die)
  "restart_timeout": 250,

  // Logging configuration
  "log": {
    // Minimum observable log level, possible values:
    // "debug", "notice", "info" (default), "warning", "fatal"
    "level": "info",

    // syslog facility to use, could be:
    // "auth", "cron", "kern", "lpr", "mail", "news", "syslog"
    // "deamon", "uucp", "local0", ... "local7"
    "facility": "user",

    // if true - logging will be printed to standard output
    "stdio": true,

    // if true - syslog will be used for logging
    "syslog": true
  },

  // Frontend configuration (i.e. TLS/SSL server)
  "frontend": {
    "port": 1443,
    "host": "0.0.0.0",

    // tcp keepalive value (in seconds)
    "keepalive": 3600,

    // if true - HAProxy compatible proxyline will be sent:
    // "PROXY TCP4 ... ... ... ..."
    "proxyline": false,

    // Which protocol versions to support:
    // "ssl23" (implies tls1.*) , "ssl3", "tls1", "tls1.1", "tls1.2"
    "security": "ssl23"
  },

  // Backend configuration (i.e. address of Cleartext server)
  "backend": {
    "port": 8000,
    "host": "127.0.0.1",
    "keepalive": 3600
  },


  // Secure contexts (i.e. Server Name Indication support)
  // NOTE: First context will be used as a default one
  "contexts": [{
    // Servername to match against
    "servername": null,

    // Path to TLS certificate
    "cert": "keys/cert.pem",

    // Path to TLS private key
    "key": "keys/key.pem",

    // Cipherlist to use
    "ciphers": null,

    // if true - server listed ciphers will be preferenced
    "server_preference": true,

    // NPN protocols to advertise
    "npn": ["http/1.1", "http/1.0"]
  }]
}
```

To start bud - create configuration file using this template and:

```bash
bud --conf conf.json
```

#### LICENSE

This software is licensed under the MIT License.

Copyright Fedor Indutny, 2013.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
USE OR OTHER DEALINGS IN THE SOFTWARE.

[0]: http://json.org/
