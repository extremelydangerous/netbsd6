# Copyright (c) 2017 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Johnny C. Lam.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

task_load random
task_load unittest

test1()
{
	describe="each \$RANDOM is different"
	local rand1 rand2 rand3
	task_random && rand1=$RANDOM
	task_random && rand2=$RANDOM
	task_random && rand3=$RANDOM
	[ "$rand1" != "$rand2" ] &&
	[ "$rand1" != "$rand3" ] &&
	[ "$rand2" != "$rand3" ]
}

test2()
{
	describe="task_random -i yields reproducible \$RANDOM"
	local first1 first2 first3
	task_random -i "12345"
	task_random && rand1=$RANDOM
	task_random && rand2=$RANDOM
	task_random && rand3=$RANDOM
	local second1 second2 second3
	task_random -i "12345"
	task_random && rand1=$RANDOM
	task_random && rand2=$RANDOM
	task_random && rand3=$RANDOM
	[ "$first1" = "$second1" ] &&
	[ "$first2" = "$second2" ] &&
	[ "$first3" = "$second3" ]
}

task_run_tests "$@"
