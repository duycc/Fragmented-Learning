// Code generated by Thrift Compiler (0.15.0). DO NOT EDIT.

package tutorial

import (
	"bytes"
	"context"
	"fmt"
	"time"
	thrift "github.com/apache/thrift/lib/go/thrift"
	"nopig.admin/gen-go/shared"

)

// (needed to ensure safety because of naive import list construction.)
var _ = thrift.ZERO
var _ = fmt.Printf
var _ = context.Background
var _ = time.Now
var _ = bytes.Equal

var _ = shared.GoUnusedProtection__
const INT32CONSTANT = 9853
var MAPCONSTANT map[string]string

func init() {
MAPCONSTANT = map[string]string{
  "goodnight": "moon",
  "hello": "world",
}

}

