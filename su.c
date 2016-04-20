/**
 * Superuser
 * Copyright (C) 2016 Sindastra <https://github.com/sindastra>
 *
 * The above copyright notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * WARNING: THIS SOFTWARE IS DANGEROUS, DO NOT USE,
 * UNLESS YOU KNOW WHAT YOU ARE DOING!
 */

#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main()
{
	if( setuid(0) != 0 )
	{
		printf("Could not setuid(0): %d: %s\n", errno, strerror(errno));
		return errno;
	}

	if( setgid(0) != 0 )
	{
		printf("Could not setgid(0): %d: %s\n", errno, strerror(errno));
		// Do not return, as setuid(0) is good enough.
	}

	if( execl("/bin/sh", "/bin/sh") == -1 )
	{
		printf("Could not execute '/bin/sh': %d: %s\n", errno, strerror(errno));
		return errno;
	}

	return 0;
}
