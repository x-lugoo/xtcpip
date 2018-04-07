

#include"lib.h"

struct list_head s_head;

struct show{
	int i;
	int count;
	struct list_head s_list;
};
void init_show(struct show *s,int n)
{
	if(s == NULL) return ;
	memset(s,0,sizeof(*s));
	s->i = n;
	s->count = n+8;
	list_add(&s->s_list,&s_head);
}

int list_test(void)
{
	struct show *s;
	

	
	list_init(&s_head);
	struct show s1,s2,s3,s4;
	init_show(&s1,1);
	init_show(&s2,2);
	init_show(&s3,3);
	init_show(&s4,4);	

	list_for_each_entry(s, &s_head, s_list){
		printf("i=%d\n",s->i);
		if(s->i == 2){
	 	struct show *pri;
	 	pri = containof(s, struct show, s_list);
		printf("count=%d\n",s->count);
	 }
	}
	printf("xtcpip\n");
	return 0;
}

int main(void)
{
	int ret;

	ret = list_test();
	return 0;
}

