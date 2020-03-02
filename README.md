# DNA_compression
DNA compression

# HOW to compress a sequence

``` sh
$ curl -vvv http://localhost/api/ -H "Content-Type: application/json" -H "Accept-Encoding: gzip, deflate" -d '{"sequence":"ACGTGCAGCAGTCAGATCTACGA"}'
```